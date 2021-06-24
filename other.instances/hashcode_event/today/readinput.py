class Book:

    def __init__(self, score, index):
        self.score = score
        self.index = index

    def __str__(self):
        result = f"Book number: {self.index} with score: {self.score}"
        return result


class Library:

    def __init__(self, books_array, signup_process, books_per_day, index):
        self.books_array = books_array
        self.signup_process = signup_process # time in days
        self.books_per_day = books_per_day
        self.index = index

    def __str__(self):
        result = f"Library{self.index}\n"
        result += f"Containing books:\n"
        result += f"{[book.index for book in self.books_array]} with score:\n"
        result += f"{[book.score for book in self.books_array]}\n"
        result += f"Signup process takes: {self.signup_process} days\n"
        result += f"Books per day: {self.books_per_day}\n"
        result += "-" * 20 + '\n'
        return result

def ReadInput(file_path):
    with open(file_path, 'r+', encoding='utf-8') as input_file:
        # books, libraries, days
        line = input_file.readline()
        total_books, total_libraries, total_days = map(int, line.split())

        # scores per book
        line = input_file.readline()
        books = [Book(score, index) for index, score in enumerate(list(map(int, line.split())))]

        libraries = []
        library_index = 0
        while line:
            # first library, second ...
            line = input_file.readline()
            lib = tuple(map(int, line.split()))
            # if we are reading the last line we dont wanna get a void string
            if lib:
                books_per_library = lib[0]
                signup_process = lib[1]
                books_per_day = lib[2]

                # books in the first library, second ...
                line = input_file.readline()
                book_indexes = list(map(int, line.split()))

                # temp array for every library
                books_array = [books[index] for index in book_indexes]

                # library0, library1 ...
                library = Library(books_array, signup_process, books_per_day, library_index)
                libraries.append(library)
                library_index += 1
            else:
                break

    return total_books, total_libraries, total_days, books, libraries