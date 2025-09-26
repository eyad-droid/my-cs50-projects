# 🖼 Filter — C

## 📖 Overview
*Filter* is a CS50 problem-set program (image filters) implemented in C.  
The goal is to implement image-processing filters that operate on 24-bit BMP images: *grayscale, **sepia, **reflect* (horizontal), *blur* (box blur), and *edges* (Sobel operator). The program reads a BMP file, applies one filter, and writes the result to an output BMP.

---

## ⚙ Features
- ✅ Grayscale conversion (average of RGB)  
- ✅ Sepia tone (classic sepia formula with clamping)  
- ✅ Horizontal reflection (mirror image)  
- ✅ Box blur (average of neighbor pixels)  
- ✅ Edge detection (Sobel operator using Gx and Gy)  
- ✅ Preserves BMP metadata; works with provided BMP helpers

---

## 📂 Project Structure

├── filter.c         # Provided main program (parses args, reads/writes BMP) ├── helpers.c        # Your implementation of the filter functions (what you edit) ├── helpers.h        # Declarations & BMP structs (provided) ├── Makefile         # Build instructions (make filter) ├── images/          # Example BMPs for testing (yard.bmp, etc.) └── README.md        # This file

---

## 🚀 Usage

1. *Compile*
```bash
make filter

2. Run The program expects a single filter flag and two filenames (infile outfile). Flags commonly used in CS50 templates:



-g → grayscale

-s → sepia

-r → reflect

-b → blur

-e → edges


Examples:

./filter -g images/yard.bmp out_gray.bmp
./filter -s images/yard.bmp out_sepia.bmp
./filter -r images/yard.bmp out_reflect.bmp
./filter -b images/yard.bmp out_blur.bmp
./filter -e images/yard.bmp out_edges.bmp


---

🧠 What to implement (helpers.c)

You will typically implement these functions (signatures come from helpers.h):

void grayscale(int height, int width, RGBTRIPLE image[height][width]);

For every pixel, compute the average of red, green, blue (round to nearest int). Set each channel to that average.


void sepia(int height, int width, RGBTRIPLE image[height][width]);

For each pixel, compute new values with:

sepiaRed   = 0.393 * r + 0.769 * g + 0.189 * b
sepiaGreen = 0.349 * r + 0.686 * g + 0.168 * b
sepiaBlue  = 0.272 * r + 0.534 * g + 0.131 * b

Clamp each channel to max 255, round to nearest integer.



void reflect(int height, int width, RGBTRIPLE image[height][width]);

For every row, swap pixels horizontally up to width / 2 (avoid double-swapping).


void blur(int height, int width, RGBTRIPLE image[height][width]);

Implement a box blur: compute each pixel’s new RGB as the average of itself and its up-to-8 neighbors. Use a temporary copy of the original image when computing new values so updates don’t affect neighbors.


void edges(int height, int width, RGBTRIPLE image[height][width]);

Apply the Sobel operator: compute Gx and Gy for each channel using kernels

Gx = [ [-1, 0, 1],
       [-2, 0, 2],
       [-1, 0, 1] ]

Gy = [ [-1, -2, -1],
       [ 0,  0,  0],
       [ 1,  2,  1] ]

For each color channel: new = round(sqrt(Gx^2 + Gy^2)), clamp to 255.

Use a copy of the original image while computing.





---

🧪 Testing & Verification

Use the images/ sample BMPs provided by CS50 (e.g., yard.bmp, moon.bmp).

Visual check: open results in any image viewer.

Command-line examples:

./filter -g images/yard.bmp yard_gray.bmp
./filter -b images/yard.bmp yard_blur.bmp

For automarked CS50 tests, ensure your output exactly matches expected byte-for-byte for the test images.



---

⚠ Common pitfalls & tips

Always use a copy of the original image when computing blur/edges; otherwise earlier writes will affect later computations.

Clamp values to [0,255] after rounding floats — forgetting to clamp causes overflow artifacts.

Edge handling: when computing neighbors (blur/edges), make sure to only include in-bounds pixels (check row/col bounds).

Reflect: iterate j from 0 to width/2 - 1, swap with width - j - 1.

Rounding: use round() when converting float averages to integers to match spec expected results.

Performance: O(height * width) per filter; blur/edges have a slightly higher constant factor — still fine for small BMPs.

Memory: temporary copy = another 2D array of RGBTRIPLE same size (stack allocation via VLA or heap via malloc). Avoid out-of-bounds indexing.



---

🧾 Edge cases

Small images (1×1, 1×N): ensure loops handle tiny dimensions.

Corners / borders when computing kernel-based filters — include only valid neighbors.

Non-BMP inputs: filter.c typically validates BMP header; do not change that behavior.



---

🛠 Requirements

C compiler (clang recommended in CS50 environment, or gcc)

Provided helpers.h / filter.c from CS50 pset — you only edit helpers.c unless instructed otherwise.



---

✅ Quick checklist before submission

All functions implemented with correct signatures.

Values rounded and clamped correctly.

No memory leaks (if you malloc, free appropriately).

Program compiles: make filter → binary filter.

Sample images processed and visually correct.

Passes check50 (if applicable).



---

👨‍💻 Author

Eyad Tamer
