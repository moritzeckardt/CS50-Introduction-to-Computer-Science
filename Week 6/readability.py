from cs50 import get_string

# Task: https://cs50.harvard.edu/x/2021/psets/6/readability/

def main():
    # Variables
    amount_letters = 0
    amount_words = 1
    amount_sentences = 0
    
    text = get_string("Text: ")
    
    # Determine amount of letters, words and sentences
    for i in range(len(text)):
        char_int = ord(text[i]) # Converts char to its int
        
        if (char_int >= 65 and char_int <= 90) or (char_int >= 97 and char_int <= 122):
            amount_letters += 1
        elif char_int == 32:
            amount_words += 1
        elif char_int == 46 or char_int == 33 or char_int == 63:
            amount_sentences += 1
            
    # Calculate value of l and s
    l = float(amount_letters) / float(amount_words) * 100
    s = float(amount_sentences) / float(amount_words) * 100
    index = round(0.0588 * l - 0.296 * s - 15.8)
    
    # Print result
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

if __name__ == "__main__":
    main() 