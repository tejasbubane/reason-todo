type todoStatus =
  | Todo
  | Doing
  | Done;

type todoItem = {
  text: string,
  status: todoStatus,
};

let nextStatus = status =>
  switch (status) {
  | Todo => Doing
  | Doing => Done
  | Done => Todo
  };

let statusLabel = status =>
  switch (status) {
  | Todo => "TODO"
  | Doing => "DOING"
  | Done => "DONE"
  };
