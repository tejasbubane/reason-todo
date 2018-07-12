open Shared;

let component = ReasonReact.statelessComponent("TodoItem");

let make = (~todo, _children) => {
  ...component,
  render: _self =>
    <div>
      <input _type="checkbox" checked=(boolStatus(todo.status)) />
      (ReasonReact.string(todo.text))
    </div>,
};
