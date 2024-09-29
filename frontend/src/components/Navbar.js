import React from 'react';
import { Link } from 'react-router-dom';
import './Navbar.css'; // Import the CSS for styling the navbar
import navBackground from '../pages/Assets/green-sky.jpg';

const Navbar = () => {
  return (
    <nav className="navbar" style={{ "--background-image": `url(${navBackground})` }}>
      <ul className="navbar-links">
        <li><Link to="/">Home</Link></li>
        <li><Link to="/code-project">Code Project</Link></li>
        <li><Link to="/team">Team</Link></li>
      </ul>
    </nav>
  );
};

export default Navbar;
