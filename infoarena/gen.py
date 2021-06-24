
import os
from string import Template

path = r'D:\__Alexzander_files__\__computer_science__\__infoarena__'

found = False

folder = input('insert folder name:\n')
for item in os.listdir(path):
    if item == folder:
        found = True

path += '\\' + folder

if not found:
    os.mkdir(path) 

while True:
    input_file_name = input('insert input file name:\n')
    decision = input('are you sure? [y]:\n')
    if decision == 'y':
        break

with open(path + '\\solutie.cpp', 'x+', encoding='utf-8') as cpp_solution:
    cpp_solution.write('#include <iostream>\n')
    cpp_solution.write('#include <fstream>\n')
    cpp_solution.write('\n')
    cpp_solution.write('using namespace std;\n')
    cpp_solution.write('\n')
    cpp_solution.write('int main() {\n')
    cpp_solution.write(f'\tifstream input("{input_file_name}.in");\n')
    cpp_solution.write(f'\tofstream output("{input_file_name}.out");\n')
    cpp_solution.write('\n')
    cpp_solution.write('\tinput.close();\n')
    cpp_solution.write('\toutput.close();\n')
    cpp_solution.write('\treturn 0;\n')
    cpp_solution.write('}')

with open(path + f'\\{input_file_name}.in', 'x+', encoding='utf-8') as in_file:
    pass

with open(path + f'\\{input_file_name}.out', 'x+', encoding='utf-8') as in_file:
    pass