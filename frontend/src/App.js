import React from 'react';
import { BrowserRouter as Router, Route, Routes, Link } from 'react-router-dom';
import About from './pages/About';
import CodeProject from './pages/CodeProject';
import Navbar from './components/Navbar' ;

function App() {
  return (
    <Router>
      <div>
      <Navbar /> {/* Ensure Navbar is used */}
      {/* Define the routes for different components */}

        <Routes>
          <Route path="/" element={<About />} />
          <Route path="/code-project" element={<CodeProject />} />
        </Routes>
      </div>
    </Router>
  );
}

export default App;
