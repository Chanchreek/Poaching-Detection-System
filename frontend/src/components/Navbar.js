import React from 'react';
import { Link } from 'react-router-dom';
import './Navbar.css'; // Import the CSS for styling the navbar

const Navbar = () => {
  return (
    <nav className="navbar">
      <ul className="navbar-links">
        <li><Link to="/">Home</Link></li>
        <li><Link to="/about">About</Link></li>
        <li><Link to="/code-project">Code Project</Link></li>
      </ul>
    </nav>
  );
};

export default Navbar;
