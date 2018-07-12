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
    <div className="container mt-5">
      <h1 className="row"> (ReasonReact.string("Todo App")) </h1>
      <div className="row">
        <Input onAdd=(text => self.send(Add(text))) />
      </div>
      <div className="row mt-5">
        <TodoList
          items=self.state
          changeStatus=((i, status) => self.send(ChangeStatus(i, status)))
        />
      </div>
    </div>,
};
