open Shared;

type state = {todos: list(todoItem)};

type action =
  | Add(string)
  | ChangeStatus(int, todoStatus);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => [],
  reducer: (action, state) =>
    switch (action) {
    | Add(text) => ReasonReact.Update([{text, status: Todo}, ...state])
    | ChangeStatus(index, status) =>
      let items =
        state |> List.mapi((i, t) => i == index ? {...t, status} : t);
      ReasonReact.Update(items);
    },
  render: self =>
    <div>
      <Input onAdd=(text => self.send(Add(text))) />
      <TodoList
        items=self.state
        changeStatus=((i, status) => self.send(ChangeStatus(i, status)))
      />
    </div>,
};
