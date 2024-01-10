def calculate_suffix(string: str) -> bool:
    rev_s = string[::-1]
    rev_suffix = rev_s[0:2]
    suffix = rev_suffix[::-1]
    if suffix == "AM":
        return True
    elif suffix == "PM":
        return False

def add_time(start: str, duration: str, day: str=None):
    new_time = ""
    if not (day is None):
        day = day.lower()
    days = ["monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"]
    # -----------------CALCULATING STARTING MINUTES AND HOURS-----------------
    # ------hours------
    s_no_of_hours = ""
    for digit in start:
        if digit == ':':
            break
        s_no_of_hours += digit
    # ------minutes------
    s_no_of_minutes = ""
    for digit in start[len(s_no_of_hours)+1:]:
        if digit == ' ':
            break
        s_no_of_minutes += digit
    # -----------------CALCULATING DURATION MINUTES AND HOURS-----------------
    d_no_of_hours = ""
    # ------minutes------
    d_no_of_minutes = ""
    for digit in duration[::-1]:
        if digit == ':':
            break
        d_no_of_minutes += digit
    d_no_of_minutes = d_no_of_minutes[::-1]
    # ------hours------
    for digit in duration:
        if digit == ':':
            break
        d_no_of_hours += digit
    # -----------------CALCULATING TOTAL DAYS, MINUTES AND HOURS-----------------
    t_no_of_days = 0
    t_no_of_hours = str(int(s_no_of_hours) + int(d_no_of_hours))
    t_no_of_minutes = str(int(s_no_of_minutes) + int(d_no_of_minutes))
    is_AM = calculate_suffix(start)
    while int(t_no_of_minutes) >= 60:
        t_no_of_minutes = int(t_no_of_minutes)
        t_no_of_minutes -= 60
        t_no_of_hours = int(t_no_of_hours)
        t_no_of_hours += 1
        t_no_of_hours = str(t_no_of_hours)
        t_no_of_minutes = str(t_no_of_minutes)

    start_is_AM = is_AM

    t_no_of_hours = int(t_no_of_hours)
    count = 0
    
    if t_no_of_hours > 12 and (not is_AM):
        is_AM = not is_AM
        t_no_of_hours -= 12
        t_no_of_days += 1
        test = False

    while (t_no_of_hours > 12) or (t_no_of_hours == 12 and int(t_no_of_minutes) > 0):
        t_no_of_hours -= 12
        count += 1
        is_AM = not is_AM
        if count >= 2:
            t_no_of_days += 1
            count = 0

    if t_no_of_hours == 0:
        t_no_of_hours = 12

    if not start_is_AM and t_no_of_hours == 12 and int(t_no_of_minutes) > 0 and test:
        t_no_of_days += 1

    t_no_of_hours = str(t_no_of_hours)
    if is_AM:
        sign = "AM"
    elif not is_AM:
        sign = "PM"

    if t_no_of_days == 0:
        pass
    elif t_no_of_days == 1:
        day_statement = " (next day)"
    elif t_no_of_days >= 2:
        day_statement = f" ({t_no_of_days} days later)"

    if int(t_no_of_minutes) < 10:
        new_time = f"{t_no_of_hours}:0{t_no_of_minutes} {sign}"
    else:
        new_time = f"{t_no_of_hours}:{t_no_of_minutes} {sign}"

    num_days_copy = t_no_of_days

    if (not (day is None)) and day in days:
            current_day_index = days.index(day)
            if t_no_of_days <= 7:
                pass
            else:
                while num_days_copy > 7:
                    num_days_copy -= 7
            required_index = current_day_index + num_days_copy
            if required_index == 7:
                required_index = 0

            weekday_statement = f", {days[required_index].capitalize()}"
            new_time += weekday_statement

    if t_no_of_days > 0:
        new_time += day_statement

    return new_time