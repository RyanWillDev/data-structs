function LinkedList() {
  let head = null,
      nodes = null,
      length = 0;

  this.head = function() {
    return head;
  };

  this.tail = function() {
    return nodes;
  }

  this.size = function() {
    return length;
  };

  this.add = function(...vals) {
    let next = head ? head : null;

    if (!vals.length) {
      throw new Error("add must be given at least one value.");
    }

    length++;

    nodes = head ? head : null;
    head = createNode({ val: vals[0], next });

    if (vals.length > 1) {
      this.add.apply(this, vals.slice(1));
    }

    return this;
  }

  function createNode({ val, next = null }) {
    return {
      val,
      next
    };
  }
}
