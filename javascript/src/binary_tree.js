exports.BinaryTree = BinaryTree;

function BinaryTree(value, left, right) {
  this.value = value;
  this.left = left || null;
  this.right = right || null;
}

BinaryTree.prototype.insert = function(value) {
  var lookingAt = this;

  while (true) {
    if (value === lookingAt.value) {
      return;
    } else if (value < lookingAt.value) {
      if (lookingAt.left === null) {
        lookingAt.left = new BinaryTree(value);
        return;
      } else {
        lookingAt = lookingAt.left;
      }

    } else if (value > lookingAt.value) {
      if(lookingAt.right === null) {
        lookingAt.right = new BinaryTree(value);
        return;
      } else {
        lookingAt = lookingAt.right;
      }
    }
  }
};

BinaryTree.prototype.contains = function(value) {
  var lookingAt = this;

  while (lookingAt !== null) {
    if (value === lookingAt.value) {
      return true;
    } else if (value < lookingAt.value) {
      lookingAt = lookingAt.left;
    } else if (value > lookingAt.value) {
      lookingAt = lookingAt.right;
    }
  }

  return false;
};

BinaryTree.prototype.mapTo = function(value) {
  var lookingAt = this
  , map = "";

  while (lookingAt !== null) {
    map += lookingAt.value;

    if (value === lookingAt.value) {
      break;
    } else if (value < lookingAt.value) {
      lookingAt = lookingAt.left;
    } else if (value > lookingAt.value) {
      lookingAt = lookingAt.right;
    }

    map += " → ";
  }

  return map;
};

