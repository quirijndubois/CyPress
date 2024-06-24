#NOT FOR PRODUCTION, just a simple proof of concept

import re

def syntax_stripper(syntax_string):
    stripped_syntax_string = repr(syntax_string)
    stripped_syntax_string = stripped_syntax_string.replace(r"\n"," \\newline ")
    stripped_syntax_string = re.sub(' +', ' ',stripped_syntax_string)

    return stripped_syntax_string

def separate(syntax_string):
    syntax_string = syntax_string[1:-1]

    delimiters = ["(",")","\\",";"] # We do not include spaces here, because its inclusion is trivial and it's behaviour differs

    tokens = []
    current_token = ""
    for char in syntax_string:
        if char == " ":
            if current_token != "":
                tokens.append(current_token)
            current_token = ""
        elif char in  delimiters:
            if not (tokens[-1] == "\\" and char == "\\"):
                if current_token != "":
                    tokens.append(current_token)
                tokens.append(char)
                current_token = ""
        else:
            current_token += char
    tokens.append(current_token)

    return tokens

def tokenize(syntax_string):
    stripped_syntax_string = syntax_stripper(syntax_string)
    syntax_list = separate(stripped_syntax_string)
    return syntax_list

if __name__ == "__main__":
    f = open("example.cyp", "r")
    syntax_string = str(f.read())

    tokens = tokenize(syntax_string)

    print(tokens)




