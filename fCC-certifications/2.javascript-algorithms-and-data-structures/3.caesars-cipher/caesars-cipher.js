function rot13(str) {
  let decoded = ''
  const rotnum = 13
  const chars = {65 : 'A', 
                 66 : 'B',
                 67 : 'C',
                 68 : 'D',
                 69 : 'E',
                 70 : 'F',
                 71 : 'G',
                 72 : 'H',
                 73 : 'I',
                 74 : 'J',
                 75 : 'K',
                 76 : 'L',
                 77 : 'M',
                 78 : 'N',
                 79 : 'O',
                 80 : 'P',
                 81 : 'Q',
                 82 : 'R',
                 83 : 'S',
                 84 : 'T',
                 85 : 'U',
                 86 : 'V',
                 87 : 'W', 
                 88 : 'X',
                 89 : 'Y',
                 90 : 'Z'}
  for (let i = 0; i < (str.length); i++) {
    let ascii_value = str[i].charCodeAt()
    if (ascii_value >= 65 && ascii_value <= 90) {
      if (ascii_value >= 78) {
        decoded += chars[ascii_value - rotnum]
      }
      else {
        let required_index = 91 - (rotnum - (ascii_value - 65))
        decoded += chars[required_index]
      }
    }
    else {
      decoded += str[i]
    }
  }
  return decoded
}

console.log(rot13("SERR PBQR PNZC"))
