// A linked list is a data structure in which individual nodes are linked
// together by pointing to each other. Specifically, a singly-linked list is one
// where the first node links to the second node by including a reference to it.
//
// Each node consists of a value as well as a reference to the next node, which
// may be null to denote that there are no further nodes in the list and that
// this node is the last node in the list.
//
// Linked lists are useful compared to arrays (in traditional languages) because
// arrays are static, they can't grow to accommodate more values. Instead you're
// forced to allocate a new bigger array and then copy over the elements to the
// new array, then deallocate the old array.
//
// Comparatively, you can append to a linked list by simply allocating memory
// for a single node (which again consists only of the value and the reference),
// then you simply make the last node in the list point to this new node in
// order to include it in the list.
//
// You should see a linked list as a collection/sequence of values, just as you
// would see an array. The difference is in how the collection is implemented
// under the hood.
//
// In Javascript, you can simply array.push(value) and stuff, but this could
// incur the cost I outlined above, even if it's hidden from you.
//
// There are many optimizations and changes you can make to this current linked
// list implementation, but you can do them later.
function List(value, next) {
  this.value = value;
  this.next = next || null;
};

// To append a new value to the collection of values represented by this linked
// list, you simply allocate a new node to hold the value and then attach it to
// the end of the list.
List.prototype.append = function(value) {
  var end = this;

  // Traverse the list by visiting each node until there is no next node, which
  // is represented by null.
  while (end.next) {
    end = end.next;
  }

  // Now that we're at the end, make it point to the new node. Notice the new
  // node points to null, meaning it's now the last node in the list.
  end.next = new List(value, null);
};

// Test two lists for equality. This necessitates traversing both lists in
// lock-step and ensuring that each corresponding node of each list is equal,
// and only then proceeding to the next node.
List.prototype.equals = function(other) {
  var a = this, b = other;

  while (a && b) {
    if (a.value != b.value) {
      return false;
    }

    a = a.next;
    b = b.next;
  }

  // One list still has elements then it means that that list is longer than the
  // other, so clearly they cannot be equal.
  if (a || b) {
    return false;
  }

  // If we reached this then they're definitely equal.
  return true;
};

// Create a linked list from an array.
List.fromArray = function(array) {
  if (array.length < 1) {
    throw "Can't build linked list from empty array!";
  }

  // Construct the first node.
  var node = new List(array[0], null);

  // A linked list is represented by its first node, so we should save a
  // reference to it.
  var head = node;

  // For each subsequent element in the array, construct a node and attach it to
  // the linked list being constructed.
  for (var i = 1; i < array.length; i++) {
    node.next = new List(array[i], null);
    node = node.next;
  }

  return head;
};

List.prototype.length = function() {
  var node = this,
      counter = 0;

  while (node !== null) {
    counter++;
    node = node.next;
  }
  return counter;
}

// Helper function to convert a linked list to a string, so you can do e.g.
// console.log(list)
List.prototype.toString = function() {
  var node = this;
  var string = "";

  // Traverse the list, adding each value to the string being built.
  while (node) {
    string += node.value;

    // If there's still another node to process, then output a cute little
    // arrow.
    if (node.next) {
      string += " → ";
    }

    node = node.next;
  }

  return string;
};

// Helper function to append an entire array.
List.prototype.appendArray = function(array) {
  var end = this;

  // Find the end of this list
  while (end.next) {
    end = end.next;
  }

  // Then append each element of the array.
  for (var i = 0; i < array.length; i++) {
    end.next = new List(array[i], null);
    end = end.next;
  }
};

List.prototype.removeNode = function removeNode(nodeToRemove) {
  var currentNode = this,
      counter = 0,
      leftEdgeNode;

  while(currentNode !== null) {
    
    // find the node to the "left" of the node to remove.
    if (counter + 1 === nodeToRemove) {
      
      // if true, there is no node to remove.
      if (currentNode.next === null) {
        return;
      }

      // otherwise, this is the node that needs to be modified.
      leftEdgeNode = currentNode;
    }

    // find the node to remove.
    else if (counter === nodeToRemove) {
      
      // if true, the left node is the end of the chain.
      if (currentNode.next === null) {
        leftEdgeNode.next = null;
        return;
      }

      // otherwise, get the next node and set the left node
      // to link to it.
      leftEdgeNode.next = currentNode.next;
      return;
    }

    currentNode = currentNode.next;
    counter++;
  }
}

exports.List = List;