import os

def combine_files(root_dir, output_file):
    with open(output_file, 'w') as outfile:
        for dirpath, dirnames, filenames in os.walk(root_dir):
            # Filter out files that don't end with .cpp or .h
            for filename in [f for f in filenames if f.endswith('.cpp') or f.endswith('.h')]:
                file_path = os.path.join(dirpath, filename)
                try:
                    # Write just the filename, without the path
                    outfile.write(f"File: {filename}\n")
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        content = infile.read()
                        outfile.write(content + "\n\n")  # Added an extra newline for separation
                except UnicodeDecodeError:
                    print(f"Skipping file due to encoding error: {filename}")
                except Exception as e:
                    print(f"An error occurred with file {filename}: {e}")

    print("All .cpp and .h files have been combined, with any unreadable files skipped.")


main_folder_path = "/Users/spartan/Documents/SJSU/Sem2/CMPE-202/Assignments/Assignment-4/CMPE-202-RPS-Assignment"
output_file_path = "/Users/spartan/Documents/SJSU/Sem2/CMPE-202/Assignments/Assignment-4/CMPE-202-RPS-Assignment/combined.txt"

# Call the function
combine_files(main_folder_path, output_file_path)
