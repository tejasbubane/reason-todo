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
    <div className="form-inline">
      <div className="form-group">
        <input
          _type="text"
          placeholder="Enter the Todo"
          className="form-control-plaintext"
          onChange=(e => self.send(UpdateText(eventVal(e))))
          value=self.state
        />
      </div>
      <button
        onClick=(_ => onAdd(self.state)) className="btn btn-primary mb-2">
        (ReasonReact.string("Add"))
      </button>
    </div>,
};
