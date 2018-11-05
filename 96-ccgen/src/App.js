import React, { Component } from 'react';
import './App.css';
import { ChromePicker } from 'react-color';

class App extends Component {

  constructor(props) {
    super(props);
    this.state = {complement: "#ffffff"};
    this.handleChange = this.handleChange.bind(this);
  }
  
  handleChange(color) {
    let r = 255 - color.rgb.r;
    let g = 255 - color.rgb.g;
    let b = 255 - color.rgb.b;
    this.setState({complement: ("#" + r.toString(16) + g.toString(16) + b.toString(16)),
		   color: color.hex});
  }
  
  render() {
    return (
      <div className="App">
        <header className="App-header">
	  
          <p>Pick a color to get its complement</p>

	  {/* onChange for some reason prevents pick from updating*/}
	  <ChromePicker color={this.state.color} onChange={ this.handleChange } disableAlpha/>
	  
	  <p>Complement:</p>

	  <div className="Comp-circle" style={{backgroundColor: this.state.complement}}></div>
	  
	  <p>Hex value: <code>{this.state.complement}</code></p>
	  
        </header>
      </div>
    );
  }
}

export default App;
