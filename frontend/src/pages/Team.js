import React from 'react';
import teamPhoto1 from './Assets/team-1.jpg'; // Replace with actual paths
import teamPhoto2 from './Assets/team-2.jpg';
import backgroundImage from './Assets/background-team.png';

const Team = () => {
  return (
    <div style={{ ...styles.container, backgroundImage: `url(${backgroundImage})` }}>
      <h1>The Team</h1>
      
      {/* Horizontal Names Section */}
      <div style={styles.namesContainer}>
        <div style={styles.name}>Aradhya Bundela</div>
        <div style={styles.name}>Angad Dogra</div>
        <div style={styles.name}>Chanchreek Jain</div>
        <div style={styles.name}>Yash Varshney</div>
      </div>
      
      {/* Photos Section */}
      <div style={styles.photosContainer}>
        <img src={teamPhoto1} alt="Alice Johnson" style={styles.photo2} />
        <img src={teamPhoto2} alt="Bob Smith" style={styles.photo} />
      </div>
      
    </div>
  );
};

const styles = {
  container: {
    textAlign: 'center',
    padding: '20px',
    color:'white',
    fontFamily: "Abril Fatface",
  },
  namesContainer: {
    display: 'flex',
    justifyContent: 'center',
    marginBottom: '20px',
    color:'white',
  },
  name: {
    margin: '0 15px',
    fontSize: '20px',
    fontWeight: '',
    fontFamily: "Abril Fatface",
  },
  photosContainer: {
    display: 'flex',
    justifyContent: 'center',
    marginBottom: '10px',
  },
  photo: {
    width: '350px', // Adjust the width as needed
    height: 'auto',
    margin: '0 10px',
    borderRadius: '8px', // Optional: Rounded corners for photos
  },
  photo2:{
    width: '660px',
    height: 'auto',
    margin: '0 10px',
    borderRadius: '8px', // Optional: Rounded corners for photos
  },
};

export default Team;
