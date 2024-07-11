# Given Boolean function F(A,B,C,D) = ∑m(1,3,4,11,12,13,14,15)
# We need to implement it using an 8:1 MUX

# Minterms corresponding to the given function
minterms = [1, 3, 4, 11, 12, 13, 14, 15]

# Number of inputs (A, B, C, D)
num_inputs = 4

# Number of select lines for the 8:1 MUX
num_select_lines = 3

# Calculate the number of data inputs required for the MUX
num_data_inputs = 2 ** num_select_lines

# Initialize the data inputs for the MUX
data_inputs = [0] * num_data_inputs

# Set the data inputs corresponding to the minterms
for minterm in minterms:
    data_inputs[minterm] = 1

# Print the data inputs
print("Data inputs for the 8:1 MUX:")
for i, data_input in enumerate(data_inputs):
    print(f"D{i} = {data_input}")

# Print the MUX implementation
print("\n8:1 MUX Implementation:")
print("Output = MUX(D0, D1, ..., D7, S2, S1, S0)")

# Print the select lines (S2, S1, S0)
for i in range(num_select_lines):
    print(f"S{i} = A{i}")

# Print the output expression
output_expression = "Output = MUX("
for i in range(num_data_inputs):
    output_expression += f"D{i}, "
output_expression += f"S2, S1, S0)"
print(output_expression)