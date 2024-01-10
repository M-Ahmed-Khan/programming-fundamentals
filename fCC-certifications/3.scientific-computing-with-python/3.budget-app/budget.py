def append_stars(s: str, n: int) -> str:
    for i in range(n):
        s += '*'
    return s


class Category:
    def __init__(self, category: str):
        self.category: str = category
        self.ledger: list = []

    def get_balance(self) -> int:
        balance = 0
        for item in self.ledger:
            balance += item["amount"]
        return balance

    def check_funds(self, amount: int) -> bool:
        if self.get_balance() >= amount:
            return True
        else:
            return False

    def deposit(self, amount, description: str = ""):
        ledger_item = {"amount": amount, "description": description}
        self.ledger.append(ledger_item)

    def withdraw(self, amount, description: str = "") -> bool:
        if not self.check_funds(amount):
            return False
        else:
            ledger_item = {"amount": (amount * (-1)), "description": description}
            self.ledger.append(ledger_item)
            return True

    def transfer(self, amount: int, destination):
        if not self.check_funds(amount):
            return False
        else:
            self.withdraw(amount, f"Transfer to {destination.category}")
            destination.deposit(amount, f"Transfer from {self.category}")
            return True

    def get_ledger_line(self, ledger_item: dict):
        line = ""
        MAX_LINE_LENGTH = 30
        description = ledger_item["description"]
        if len(description) > 23:
            description = description[0:23]
        desc_length = len(description)
        amount = str(round(float(ledger_item["amount"]), 2))
        count = 0
        for i in amount[amount.index('.') + 1:]:
            count += 1
        if count == 1:
            amount += '0'
        amt_length = len(amount)
        no_of_spaces = MAX_LINE_LENGTH - (desc_length + amt_length)
        line += description
        for i in range(no_of_spaces):
            line += ' '
        line += amount
        return line

    def __str__(self):
        message = ""
        no_of_stars_in_title: int = int((30 - len(self.category)) / 2)
        title = self.category
        title = append_stars(title, no_of_stars_in_title)
        title = append_stars(title[::-1], no_of_stars_in_title)
        title = title[::-1]
        message += f"{title}\n"
        for ledger_item in self.ledger:
            message += f"{self.get_ledger_line(ledger_item)}\n"
        message += f"Total: {self.get_balance()}"
        return message


def round_to_nearest_ten(n: int) -> int:
    last_digit = n % 10
    return n - last_digit


def to_char_array(s: str) -> list:
    char_array = []
    for character in s:
        char_array.append(character)
    return char_array


def create_spend_chart(categories: list):
    amounts = []
    sum_of_amounts = 0
    percentages = []
    category_list = []
    for category in categories:
        category_list.append(category.category)
        amount = 0
        for ledger_item in category.ledger:
            if ledger_item["amount"] < 0:
                amount += abs(ledger_item["amount"])
        amounts.append(amount)
        sum_of_amounts += amount

    for amount in amounts:
        percentage = int(((amount / sum_of_amounts) * 100) // 1)
        percentage = round_to_nearest_ten(percentage)
        percentages.append(percentage)

    bar_chart = "Percentage spent by category\n"
    for value in reversed(range(0, 101, 10)):
        if value == 0:
            string = "  " + str(value) + "|"
        elif value < 100:
            string = " " + str(value) + "|"
        else:
            string = str(value) + "|"
        for i in percentages:
            if i >= value:
                string += " o "
            else:
                string += "   "

        bar_chart += string + ' \n'
    dashes = "    " + ("-" * 3) * len(amounts) + "-\n"
    bar_chart += dashes
    longest_str = max(category_list, key=len)
    longest_str_num = len(longest_str)
    for value in range(0, longest_str_num):
        bar_chart += "    "
        number = 1
        for category in category_list:
            if len(category) > value:
                bar_chart += (" " + category[value] + " ")
                if number == len(category_list):
                    bar_chart += " "
            else:
                bar_chart += "   "
            number += 1
        bar_chart += "\n"
    bar_chart = bar_chart.rstrip()
    bar_chart += "  "

    return bar_chart
