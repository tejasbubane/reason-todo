open Shared;

let component = ReasonReact.statelessComponent("TodoItem");

let statusClass = status =>
  switch (status) {
  | Todo => "danger"
  | Doing => "warning"
  | Done => "success"
  };

let make = (~todo, ~changeStatus, _children) => {
  ...component,
  render: _self =>
    <div>
      <span className=("badge mr-3 badge-" ++ statusClass(todo.status))>
        (todo.status |> statusLabel |> ReasonReact.string)
      </span>
      <span
        onClick=(_e => todo.status |> nextStatus |> changeStatus)
        style=(ReactDOMRe.Style.make(~cursor="pointer", ()))>
        (ReasonReact.string(todo.text))
      </span>
    </div>,
};
