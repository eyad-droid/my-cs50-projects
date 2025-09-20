import os
from flask import Flask, render_template, request, redirect, session

app = Flask(__name__)
# Set a secret key for sessions
# In a real app, use a strong, random key from environment variables
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

# Use a session to store tasks. This is temporary.
# When the server restarts, all tasks will be lost.
# We are storing them in 'session' for each user.
# The session is not persistent across server restarts.

@app.before_request
def initialize_tasks():
    # Initialize the tasks list in the session if it doesn't exist
    if 'tasks' not in session:
        session['tasks'] = []

@app.route("/")
def index():
    # Get tasks from the session
    tasks = session.get('tasks', [])
    return render_template("index.html", tasks=tasks)

@app.route("/add", methods=["POST"])
def add():
    title = request.form.get("title", "").strip()
    if title:
        # Get tasks from the session
        tasks = session.get('tasks', [])
        # Add a new task to the list
        tasks.append({'id': len(tasks), 'title': title, 'done': 0})
        # Update the session with the new tasks list
        session['tasks'] = tasks
    return redirect("/")

@app.route("/toggle/<int:task_id>", methods=["POST"])
def toggle(task_id):
    # Get tasks from the session
    tasks = session.get('tasks', [])
    for task in tasks:
        if task['id'] == task_id:
            # Toggle the 'done' status
            task['done'] = 1 if task['done'] == 0 else 0
            break
    # Update the session with the modified tasks list
    session['tasks'] = tasks
    return redirect("/")

@app.route("/delete/<int:task_id>", methods=["POST"])
def delete(task_id):
    # Get tasks from the session
    tasks = session.get('tasks', [])
    # Filter out the task with the given ID
    tasks = [task for task in tasks if task['id'] != task_id]
    # Re-assign IDs to avoid issues with newly added items
    for i, task in enumerate(tasks):
        task['id'] = i
    # Update the session with the new tasks list
    session['tasks'] = tasks
    return redirect("/")

if __name__ == "__main__":
    app.run(debug=True, host="127.0.0.1", port=5000)
