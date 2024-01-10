function telephoneCheck(str) {
  let formats = [/^(1\s?)?\d{3}([-\s]?)\d{3}\2\d{4}$/, 
                 /^(1\s?)?\(\d{3}\)\s?\d{3}[-\s]?\d{4}$/];
  for (let i = 0; i < 2; i++) {
    if (formats[i].test(str)) {
      return true
    }
  }
  return false
}

telephoneCheck("1 (555) 555-5555");
