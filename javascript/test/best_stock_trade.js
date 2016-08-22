var chai = require('chai');
var assert = chai.assert;

var getMaxProfit = require('./../src/best_stock_trade');

describe('Best Stock Trade', function() {
  var stockPricesYesterday = [10, 7, 11, 8, 6, 9];
  var expectedBestProfit = 4;

  var bestProfit = getMaxProfit.getMaxProfitSlow(stockPricesYesterday);

  it('should find greatest profit', function() {
    assert.equal(expectedBestProfit, bestProfit);
  });
});