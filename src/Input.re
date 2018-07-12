open Shared;

type state = todoItem;

type action =
  | UpdateTodo(string);

let component = ReasonReact.reducerComponent("Input");
let eventVal = event => ReactDOMRe.domElementToObj(
                          ReactEventRe.Form.target(event),
                        )##value;

let make = (~onAdd, _children) => {
  ...component,
  initialState: () => {text: "", status: Todo},
  reducer: (action, state) =>
    switch (action) {
    | UpdateTodo(value) => ReasonReact.Update({...state, text: value})
    },
  render: self =>
    <div>
      <input
        _type="text"
        placeholder="Enter the Todo"
        onChange=(e => self.send(UpdateTodo(eventVal(e))))
        value=self.state.text
      />
      <button onClick=(_ => onAdd(self.state))>
        (ReasonReact.string("Add"))
      </button>
    </div>,
};
