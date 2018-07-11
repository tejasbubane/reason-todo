open Shared;

type state = {todos: list(todoItem)};

type action =
  | Add(todoItem);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => [],
  reducer: (action, state) =>
    switch (action) {
    | Add(item) => ReasonReact.Update([item.text, ...state])
    },
  render: self =>
    <div>
      <Input onAdd=(todo => self.send(Add(todo))) />
      <TodoList items=self.state />
    </div>,
};
