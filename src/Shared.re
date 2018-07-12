type status =
  | Todo
  | Done;

type todoItem = {
  text: string,
  status,
};

let boolStatus = status =>
  switch (status) {
  | Todo => false
  | Done => true
  };
