

def PrintLibraries(libraries):
    for library in libraries:
        print(library)

def ComputeProblem(filepath, total_books, total_libraries, total_days, books, libraries, result_file_name):
    # the algorithm -->> aplying greedy method because im outta timeeee

    # we sort the libraries descending after signup time
    libraries = sorted(libraries, key=lambda library: library.signup_process, reverse=True)

    # we sort the books descending after the score
    for index in range(len(libraries)):
        libraries[index].books_array = sorted(libraries[index].books_array,
                                              key=lambda book_class: book_class.score,
                                              reverse=True)

    # array with libraries that will sign-up and send books to scan
    solution = []
    for library in libraries:
        start = 0
        if library.signup_process < total_days:
            start += library.signup_process
            # number of books sent by library
            sent_books_number = total_days - start
            sent_books = [library.books_array[index].index for index in range(sent_books_number)]
            solution.append((library, sent_books_number, sent_books))

    result_folder = "C:\\Andrew_Stuff\\python_stuff\\" \
                    "andrew_packages\\programming_problems\\" \
                    "hashcode_event\\today\\result\\"

    name = files[0][0]
    result_path = result_folder + result_file_name + "_" + "result.txt"
    with open(result_path, 'w+', encoding='utf-8') as result_file:
        line = str(len(solution)) + '\n'
        result_file.write(line)
        for sol in solution:
            line = f"{sol[0].index} {sol[1]}\n"
            result_file.write(line)
            line = ""
            for book_score in sol[2]:
                line += str(book_score) + " "
            line = line[:len(line) - 1]
            line += '\n'
            result_file.write(line)

if __name__ == '__main__':
    import os
    files_abs_path = "C:\\Andrew_Stuff\\python_stuff\\" \
                     "andrew_packages\\programming_problems\\" \
                     "hashcode_event\\today\\files_4_today\\"
    files = os.listdir(files_abs_path)
    files.pop()
    from time import sleep
    from andrew_packages.programming_problems.hashcode_event.today.readinput import *
    literals = "abcdef"
    for file, letter in zip(files, list(literals)):
        total_books, total_libraries, total_days, books, libraries = ReadInput(files_abs_path + file)
        ComputeProblem(files_abs_path + file, total_books, total_libraries, total_days, books, libraries, letter)
        sleep(1)


