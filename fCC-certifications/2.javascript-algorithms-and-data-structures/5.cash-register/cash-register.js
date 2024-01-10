function checkCashRegister(price, cash, cid) {
  let coins = [
    ["PENNY", 0.01],
    ["NICKEL", 0.05],
    ["DIME", 0.1],
    ["QUARTER", 0.25],
    ["ONE", 1],
    ["FIVE", 5],
    ["TEN", 10],
    ["TWENTY", 20],
    ["ONE HUNDRED", 100],
  ];
  let change_v = [
    ["PENNY", 0],
    ["NICKEL", 0],
    ["DIME", 0],
    ["QUARTER", 0],
    ["ONE", 0],
    ["FIVE", 0],
    ["TEN", 0],
    ["TWENTY", 0],
    ["ONE HUNDRED", 0],
  ];
  let status_v = "";

  let change_amt = cash - price;
  const ftotal_cash = (arr) => {
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
      sum += arr[i][1];
    }
    return +sum.toFixed(2);
  };
  let total_cash = ftotal_cash(cid);
  if (change_amt > total_cash) {
    status_v = "INSUFFICIENT_FUNDS";
    change_v = [];
    return { status: status_v, change: change_v };
  } else if (change_amt == total_cash) {
    status_v = "CLOSED";
    change_v = cid;
    let closed_change_v = []
    for (let i = change_v.length - 1; i >= 0; i--) {
      if (change_v[i][1] > 0) {
        closed_change_v.push(change_v[i]);
      }
    }
    return { status: status_v, change: closed_change_v };
  }
  while (change_amt != 0) {
    let pass = false;
    if (change_amt >= 100 || pass) {
      if (cid[8][1] <= 0) {
        pass = true;
      } else {
        cid[8][1] -= coins[8][1];
        change_v[8][1] += coins[8][1];
        change_amt -= coins[8][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 20 && change_amt < 100) || pass) {
      if (cid[7][1] <= 0) {
        pass = true;
      } else {
        cid[7][1] -= coins[7][1];
        change_v[7][1] += coins[7][1];
        change_amt -= coins[7][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 10 && change_amt < 20) || pass) {
      if (cid[6][1] <= 0) {
        pass = true;
      } else {
        cid[6][1] -= coins[6][1];
        change_v[6][1] += coins[6][1];
        change_amt -= coins[6][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 5 && change_amt < 10) || pass) {
      if (cid[5][1] <= 0) {
        pass = true;
      } else {
        cid[5][1] -= coins[5][1];
        change_v[5][1] += coins[5][1];
        change_amt -= coins[5][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 1 && change_amt < 5) || pass) {
      if (cid[4][1] <= 0) {
        pass = true;
      } else {
        cid[4][1] -= coins[4][1];
        change_v[4][1] += coins[4][1];
        change_amt -= coins[4][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 0.25 && change_amt < 1) || pass) {
      if (cid[3][1] <= 0) {
        pass = true;
      } else {
        cid[3][1] -= coins[3][1];
        change_v[3][1] += coins[3][1];
        change_amt -= coins[3][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 0.1 && change_amt < 0.25) || pass) {
      if (cid[2][1] <= 0) {
        pass = true;
      } else {
        cid[2][1] -= coins[2][1];
        change_v[2][1] += coins[2][1];
        change_amt -= coins[2][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if ((change_amt >= 0.05 && change_amt < 0.1) || pass) {
      if (cid[1][1] <= 0) {
        pass = true;
      } else {
        cid[1][1] -= coins[1][1];
        change_v[1][1] += coins[1][1];
        change_amt -= coins[1][1];
        change_amt = +change_amt.toFixed(2);
        continue;
      }
    }
    if (change_amt < 0.05 || pass) {
      if (cid[0][1] <= 0) {
        status_v = "INSUFFICIENT_FUNDS";
        change_v = [];
        return { status: status_v, change: change_v };
      }
      cid[0][1] -= coins[0][1];
      change_v[0][1] += coins[0][1];
      change_amt -= coins[0][1];
      change_amt = +change_amt.toFixed(2);
      continue;
    }
  }
  let clean_change_v = [];
  for (let i = change_v.length - 1; i >= 0; i--) {
    if (change_v[i][1] > 0) {
      clean_change_v.push(change_v[i]);
    }
  }
  status_v = "OPEN";
  return { status: status_v, change: clean_change_v };
}

console.log(
  checkCashRegister(100, 570, [
    ["PENNY", 0],
    ["NICKEL", 0],
    ["DIME", 0],
    ["QUARTER", 0],
    ["ONE", 100],
    ["FIVE", 50],
    ["TEN", 20],
    ["TWENTY", 100],
    ["ONE HUNDRED", 200],
  ])
);
