let component = ReasonReact.statelessComponent("TodoList");

let make = (~items, ~changeStatus, _children) => {
  ...component,
  render: _self =>
    <ul>
      (
        items
        |> List.mapi((i, item) =>
             <li>
               <TodoItem
                 key=(string_of_int(i))
                 todo=item
                 changeStatus=(changeStatus(i))
               />
             </li>
           )
        |> Array.of_list
        |> ReasonReact.array
      )
    </ul>,
};
