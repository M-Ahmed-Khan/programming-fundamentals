def get_number_from_string(string: str, starting_position: int, ending_position: int):
    if starting_position is None and ending_position is None:
        raw_number = string
    elif starting_position is None:
        raw_number = string[:ending_position]
    elif ending_position is None:
        raw_number = string[starting_position:]
    else:
        raw_number = string[starting_position:ending_position]

    clean_number = ""
    for digit in raw_number:
        if digit.isdigit():
            clean_number += digit
        if not (digit.isdigit() or digit.isspace() or digit == '+' or digit == '-' or digit == '*' or digit == '/'):
            return None
    return clean_number

def get_digit_length(string: str):
    length_1st_num = 0
    for digit in string:
        if not digit.isspace():
            length_1st_num += 1
        else:
            break
    
    rev_string = string[::-1]
    length_2nd_num = 0
    for digit in rev_string:
        if not digit.isspace():
            length_2nd_num += 1
        else:
            break

    if length_1st_num > 4 or length_2nd_num > 4:
        return False
    else: 
        return True

def get_answer_of_problem(problem: str, first_num: str, second_num: str):
    ADDITION = '+'
    SUBTRACTION = '-'
    if problem[len(first_num) + 1] == ADDITION:
        answer = int(first_num) + int(second_num)
        sign = ADDITION
    elif problem[len(first_num) + 1] == SUBTRACTION:
        answer = int(first_num) - int(second_num)
        sign = SUBTRACTION
    
    return (answer, sign)

def get_sign(problem: str):
    raw_first_num = problem[0:4]
    clean_first_num = ""
    for digit in raw_first_num:
        if not (digit.isspace() or digit == '+' or digit == '-' or digit == '*' or digit == '/'):
            clean_first_num += digit
    ADDITION = '+'
    SUBTRACTION = '-'
    MULTIPLICATION = '*'
    DIVISION = '/'
    if problem[len(clean_first_num) + 1] == ADDITION:
        sign = ADDITION
    elif problem[len(clean_first_num) + 1] == SUBTRACTION:
        sign = SUBTRACTION
    elif problem[len(clean_first_num) + 1] == MULTIPLICATION:
        sign = MULTIPLICATION
    elif problem[len(clean_first_num) + 1] == DIVISION:
        sign = DIVISION
    
    return sign

def get_problem_lines(first_num: str, second_num: str, sign: str, answer: int, display_answer: bool):
    if len(first_num) > len(second_num):
        longest = len(first_num)
    else:
        longest = len(second_num)
    THIRD_LINE = ('-' * longest) + "--"
    LINE_LENGTH = len(THIRD_LINE)
    gaps_1st_line = LINE_LENGTH - len(first_num)
    gaps_2nd_line = (LINE_LENGTH - len(second_num)) - 1
    gaps_4th_line = LINE_LENGTH - len(str(answer))

    first_line = f"{' ' * gaps_1st_line}{first_num}"
    second_line = f"{sign}{' ' * gaps_2nd_line}{second_num}"
    if display_answer:
        fourth_line = f"{' ' * gaps_4th_line}{answer}"
        return (first_line, second_line, THIRD_LINE, fourth_line)
    else:
        return (first_line, second_line, THIRD_LINE)
    
def join_lines(problems: str, lines: list, last_line: bool=False):
    j = 0
    for line in lines:
        if not line is None:
            if j == 0:
                problems += f"{line}"
            else:
                problems += f"    {line}"
        j += 1
    
    if not last_line:
        problems += '\n'

    return problems

def plain_arranger(problems: list, display_answer: bool=False):
    arranged_problems = ""
    first_lines = [None, None, None, None, None]
    second_lines = [None, None, None, None, None]
    third_lines = [None, None, None, None, None]
    fourth_lines = [None, None, None, None, None]
    i = 0
    for problem in problems:
        first_number = get_number_from_string(problem, 0, 4)
        if first_number is None:
            return None
        second_number = get_number_from_string(problem, len(problem) - 4, None)
        if second_number is None:
            return None

        answer, sign = get_answer_of_problem(problem, first_number, second_number)
        if not display_answer:
            first_lines[i], second_lines[i], third_lines[i] = get_problem_lines(first_number, second_number, sign, answer, display_answer)
        else:
            first_lines[i], second_lines[i], third_lines[i], fourth_lines[i] = get_problem_lines(first_number, second_number, sign, answer, display_answer)
        i += 1

    arranged_problems = join_lines(arranged_problems, first_lines)
    arranged_problems = join_lines(arranged_problems, second_lines)
    if display_answer:
        arranged_problems = join_lines(arranged_problems, third_lines)
    else:
        arranged_problems = join_lines(arranged_problems, third_lines, True)
    if display_answer:
        arranged_problems = join_lines(arranged_problems, fourth_lines, True)

    return arranged_problems

def arithmetic_arranger(problems: list, display_answer: bool=False):
    PROBLEM_LIMIT = 5
    if len(problems) > PROBLEM_LIMIT:
        return "Error: Too many problems."
    
    for problem in problems:
        if not get_digit_length(problem):
            return "Error: Numbers cannot be more than four digits."
    
    for problem in problems:
        if get_sign(problem) == '*' or get_sign(problem) == '/':
            return "Error: Operator must be '+' or '-'."
        
    if plain_arranger(problems, display_answer) is None:
        return "Error: Numbers must only contain digits."

    arranged_problems = plain_arranger(problems, display_answer)
    return arranged_problems

print(arithmetic_arranger(["1 + 55", "90 - 77", "1000 + 9000", "876 - 321", "1234 + 5678"], True))