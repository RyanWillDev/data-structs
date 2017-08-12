function linkedList(...args) {
  const emptyList = {
    nodes: null,
    length: 0,
    head: null
  };

  if (args.length < 1) {
    return Object.freeze(emptyList);
  }

  if (args.length === 1) {
    return add(args[0], emptyList);
  }

  return args.reduce((acc, val) => {
    return add(val, acc);
  }, { nodes: null, length: 0 });
}

function add(val, list) {
  let newList = Object.assign({}, list);

  newList.nodes = newList.head ? newList.head : null;

  newList.head = {
    val,
    next: newList.nodes ? newList.nodes : null
  }

  newList.length++;

  return Object.freeze(newList);
}

function head(list) {
  return list.head;
}

function tail(list) {
  return list.nodes;
}
