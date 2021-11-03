import sys
import csv

# Task: https://cs50.harvard.edu/x/2021/psets/6/dna/

def main():
    # Check input
    if len(sys.argv) != 3:
        print("Usuage: python dna.py data.csv sequene.txt")
    
    # Read txt file
    with open(sys.argv[2], "r") as file:
        reader = csv.DictReader(file)
        sequence = file.readline()
        
    # Read csv file
    persons = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        
        # Case 1: arge file (identical to case 2)
        large_file = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
        if sys.argv[1] == 'databases/large.csv':
            for row in reader:
                for i in range(len(large_file)):
                    # Convert row from string to int
                    row[large_file[i]] = int(row[large_file[i]])
                    
                # Add rows to list
                persons.append(row)
            
            # Retrieve str codes
            str_counts = detect_str(sequence, large_file)
            
            # Loop through all persons and find match
            for i in range(len(persons)):
                matches = 0
                for x in range(len(large_file)):
                    if persons[i][large_file[x]] == str_counts[x]:
                        matches += 1
                        
                # Print success
                if matches == len(large_file):
                    print(persons[i]["name"])
            
            # Print failure
            if matches != len(large_file):
                print("No match")
        
        
        # Case 2: Small file (identical to case 1)
        small_file = ["AGATC", "AATG", "TATC"]   
        if sys.argv[1] == 'databases/small.csv':
            for row in reader:
                for i in range(len(small_file)):
                    # Convert row from string to int
                    row[small_file[i]] = int(row[small_file[i]])
               
                # Add rows to list
                persons.append(row)
            
            # Retrieve str codes
            str_counts = detect_str(sequence, small_file)
            
            # Loop through all persons and find match
            for i in range(len(persons)):
                matches = 0
                for x in range(len(small_file)):
                    if persons[i][small_file[x]] == str_counts[x]:
                        matches += 1
                       
                # Print success 
                if matches == len(small_file):
                    print(persons[i]["name"])
            
            # Print failure
            if matches != len(small_file):
                print("No match")
        
# Detect longest runs of all str codes
def detect_str(sequence, file):
    max_counts = []
    
    # Loop through all str codes
    for i in range(len(file)):
        max_counts.append(0)
        # Look at every character of the sequence by looping through
        for j in range(len(sequence)):
            current_count = 0
            
            # If STR found
            if sequence[j:(j + len(file[i]))] == file[i]:
                k = 0
                
                # Look for a consecutive run and increase counter
                while sequence[(j + k):(j + k + len(file[i]))] == file[i]:
                    current_count += 1
                    k += len(file[i])
                    
                # Compare current and max counter
                if current_count > max_counts[i]:
                    max_counts[i] = current_count
                    
    return max_counts
    
    
if __name__ == "__main__":
    main()
    
        
    