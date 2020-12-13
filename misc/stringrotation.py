
def checkIfRotated(str_a, str_b):

    if len(str_a) == 0 and len(str_b) == 0:
        return True
    if len(str_a) != len(str_b):
        return False
    
    return str_a[2:]+str_a[0:2] == str_b

string_a = "amazon"
string_b = "azonam"

print("Result:",checkIfRotated(string_a, string_b))