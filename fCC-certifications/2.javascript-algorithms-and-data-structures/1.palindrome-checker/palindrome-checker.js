const reverse_str = (str) => {
  let rev_str = str.split("").reverse().join("")
  return rev_str
}

const remove_whitespace_and_punc = (str) => {
  str = str.split(' ').join('')
  str = str.split('_').join('')
  str = str.split('.').join('')
  str = str.split(',').join('')
  str = str.split('/').join('')
  str = str.split('"').join('')
  str = str.split("'").join('')
  str = str.split(':').join('')
  str = str.split(';').join('')
  str = str.split('-').join('')
  str = str.split('|').join('')
  str = str.split('\\').join('')
  return str
}

const remove_special_chars = (str) => {
  str = str.split('~').join('')
  str = str.split('`').join('')
  str = str.split('!').join('')
  str = str.split('@').join('')
  str = str.split('#').join('')
  str = str.split('$').join('')
  str = str.split('%').join('')
  str = str.split('^').join('')
  str = str.split('&').join('')
  str = str.split('*').join('')
  str = str.split('(').join('')
  str = str.split(')').join('')
  str = str.split('+').join('')
  str = str.split('=').join('')
  return str
}

function palindrome(str) {
  let clean_string = reverse_str(str)
  clean_string = clean_string.trim()
  clean_string = remove_special_chars(clean_string)
  clean_string = remove_whitespace_and_punc(clean_string)
  clean_string = clean_string.toLowerCase()
  let reversed_string = reverse_str(clean_string)
  if (clean_string == reversed_string) {
    return true
  }
  else {
    return false
  }
}

palindrome("eye")