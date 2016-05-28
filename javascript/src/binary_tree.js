exports.BinaryTree = BinaryTree;

function BinaryTree(value, left, right) {
  this.value = value;
  this.left = left || null;
  this.right = right || null;
}

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