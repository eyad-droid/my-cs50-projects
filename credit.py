from cs50 import get_string

# ناخد رقم الكارت من المستخدم
number = get_string("Number: ")

# دالة للتحقق بخوارزمية Luhn
def check_luhn(card_number):
    total = 0
    length = len(card_number)
    reverse_digits = card_number[::-1]

    for i in range(length):
        n = int(reverse_digits[i])
        # نضرب كل تاني رقم ×2 (بدءًا من التاني من اليمين)
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9
        total += n

    return total % 10 == 0

# التحقق
if check_luhn(number):
    if number.startswith("4") and len(number) in [13, 16]:
        print("VISA")
    elif number[:2] in ["34", "37"] and len(number) == 15:
        print("AMEX")
    elif number[:2] in ["51", "52", "53", "54", "55"] and len(number) == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")