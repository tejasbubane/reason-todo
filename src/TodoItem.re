open Shared;

let component = ReasonReact.statelessComponent("TodoItem");

let make = (~todo, ~changeStatus, _children) => {
  ...component,
  render: _self =>
    <div>
      <span> (todo.status |> statusLabel |> ReasonReact.string) </span>
      <span onClick=(_e => todo.status |> nextStatus |> changeStatus)>
        (ReasonReact.string(todo.text))
      </span>
    </div>,
};
