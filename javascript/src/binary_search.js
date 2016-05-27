module.exports.array = function(arr, value) {
  var leftBound = 0,
      rightBound = arr.length - 1,
      middle = Math.floor(rightBound / 2);
      

  while (middle !== leftBound && middle !== rightBound) {
    if (arr[middle] === value) {
      return true;

    } else if (arr[middle] < value) {
      leftBound = middle;
      middle = Math.ceil((rightBound - leftBound) / 2) + leftBound;

    } else if (arr[middle] > value) {
      rightBound = middle;
      middle = Math.floor((rightBound - leftBound) / 2) + leftBound;
    }

    if (middle === 0 || middle === arr.length - 1) {
      if (arr[middle] === value) {
        return true;
      }
    }
  }
  return false;
}
