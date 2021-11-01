from cs50 import get_int
import re
import sys

# Task: https://cs50.harvard.edu/x/2021/psets/6/credit/

def main():
    # Variables
    even_sum = 0
    odd_sum = 0
    
    card = str(get_int("Number: "))
    
    if len(card) < 13:
        print("INVALID")
        sys.exit(1)
    
    for i in range(len(card)-2, -1, -2):
        digit = int(card[i]) * 2
        if digit >= 10:
            even_sum += int(digit / 10) + (digit % 10)
        else:
            even_sum += digit
    
    for i in range(len(card)-1, -1, -2):
        digit = int(card[i])
        odd_sum += digit
    
    final_sum = even_sum + odd_sum
    
    if((final_sum % 10) != 0):
        print("INVALID")
    else:
        if(re.match("34", card) or re.match("37", card)):
            print("AMEX")
        elif(re.match("4", card)):
            print("VISA")
        elif(re.match("51", card) or re.match("52", card) or re.match("53", card) or re.match("54", card) or re.match("55", card)):
            print("MASTERCARD")
            
if __name__ == "__main__":
    main()   
