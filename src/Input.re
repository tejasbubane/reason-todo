open Shared;

type state = string;

type action =
  | UpdateText(string);

let component = ReasonReact.reducerComponent("Input");
let eventVal = event => ReactDOMRe.domElementToObj(
                          ReactEventRe.Form.target(event),
                        )##value;

let make = (~onAdd, _children) => {
  ...component,
  initialState: () => "",
  reducer: (action, _state) =>
    switch (action) {
    | UpdateText(value) => ReasonReact.Update(value)
    },
  render: self =>
    <div>
      <input
        _type="text"
        placeholder="Enter the Todo"
        onChange=(e => self.send(UpdateText(eventVal(e))))
        value=self.state
      />
      <button onClick=(_ => onAdd(self.state))>
        (ReasonReact.string("Add"))
      </button>
    </div>,
};
