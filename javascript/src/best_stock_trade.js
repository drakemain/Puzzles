module.exports.getMaxProfitSlow = function(prices) {
  var largestProfit = null;
  var profit = null;
  for (var i = 0; i < prices.length - 1; i++) {
    for (var j = i + 1; j < prices.length; j++) {
      profit = prices[j] - prices[i];

      if (largestProfit === null || profit > largestProfit) {
        largestProfit = profit;
      }

      console.log('Buy: ', prices[i], ', Sell: ', prices[j], ', Profit: ', profit, 
        ', LProfit: ', largestProfit);
    }
  }

  return largestProfit;
};