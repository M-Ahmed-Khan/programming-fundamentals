function convertToRoman(num) {
  let roman_num = "";
  let count = 0
  while (num != 0) {
    if (num < 4000 && num >= 1000) {
      count = 0
      for (let i = 1000; i <= num; i += 1000) {
        roman_num += "M"
        count += 1000
      }
      num -= count
    }
    if (num < 1000 && num >= 900) {
      roman_num += "CM"
      num -= 900
    }
    if (num < 900 && num >= 500) {
      roman_num += "D"
      num -= 500
    }
    if (num < 500 && num >= 400) {
      roman_num += "CD"
      num -= 400
    }
    if (num < 400 && num >= 100) {
      count = 0
      for (let i = 100; i <= num; i += 100) {
        roman_num += "C"
        count += 100
      }
      num -= count
    }
    if (num < 100 && num >= 90) {
      roman_num += "XC"
      num -= 90
    }
    if (num < 90 && num >= 50) {
      roman_num += "L"
      num -= 50
    }
    if (num < 50 && num >= 40) {
      roman_num += "XL"
      num -= 40
    }
    if (num < 40) {
      count = 0
      for (let i = 10; i <= num; i += 10) {
        roman_num += "X"
        count += 10
      }
      num -= count
    }
    if (num < 10) {
      if (num == 9) {
        roman_num += "IX"
        num -= 9
      }
      if (num >= 5) {
        roman_num += "V"
        num -= 5
      }
      if (num == 4) {
        roman_num += "IV"
        num -= 4
      }
      if (num <= 3) {
        count = 0
        for (let i = 0; i < num; i++) {
          roman_num += "I";
          count++
        }
        num -= count
      }
    }
  }
  return roman_num;
}

console.log(convertToRoman(36));

/* Reference Chart
 * Roman numerals	| Arabic numerals
 *      M	        |      1000
 * ---------------------------------
 *     CM	        |       900
 * ---------------------------------
 *      D	        |       500      C
 * ---------------------------------
 *     CD	        |       400      C
 * ---------------------------------
 *      C	        |       100      C
 * ---------------------------------
 *     XC	        |        90      C
 * ---------------------------------
 *      L	        |        50      C
 * ---------------------------------
 *     XL	        |        40      C
 * ---------------------------------
 *      X	        |        10      C
 * ---------------------------------
 *     IX	        |         9      C
 * ---------------------------------
 *      V	        |         5      C
 * ---------------------------------
 *     IV	        |         4      C
 * ---------------------------------
 *      I	        |         1      C
 */
