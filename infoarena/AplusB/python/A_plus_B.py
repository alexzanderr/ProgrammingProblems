
with open("adunare.in", 'r', encoding='utf-8') as input_file:
    a = input_file.readline()
    a = int(a[:len(a) - 1])
    b = input_file.readline()
    b = int(b)

with open("adunare.out", 'w', encoding='utf-8') as output_file:
    output_file.write(str(a + b))
