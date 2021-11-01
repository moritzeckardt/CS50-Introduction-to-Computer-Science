from cs50 import get_int

# Task: https://cs50.harvard.edu/x/2021/psets/6/mario/more/
   
def main():
    # Enter height & determine amounf of spaces
    while True:
        height = get_int("Height of pyramides (1 - 8): ")
        if height > 0 and height < 9:
            amount_spaces = height - 1
            break
    
    # Build pyramide
    for i in range(1, height + 1):
        amount_hashes = i
        amount_spaces = height - amount_hashes

        print(" " * amount_spaces, end="")
        
        print("#" * amount_hashes, end="")

        print("  ", end="")

        print("#" * amount_hashes)


if __name__ == "__main__":
    main()   
