let component = ReasonReact.statelessComponent("TodoList");

let make = (~items, _children) => {
  ...component,
  render: _self =>
    items
    |> List.mapi((i, item) =>
         <div key=(string_of_int(i))> (ReasonReact.string(item)) </div>
       )
    |> Array.of_list
    |> ReasonReact.array,
};
