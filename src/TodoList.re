let component = ReasonReact.statelessComponent("TodoList");

let make = (~items, _children) => {
  ...component,
  render: _self =>
    items
    |> List.mapi((i, item) => <TodoItem key=(string_of_int(i)) todo=item />)
    |> Array.of_list
    |> ReasonReact.array,
};
