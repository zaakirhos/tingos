import axios from 'axios'

export default axios.create({
  baseUrl: "http://localhost:8000/api/v1/restaurants",
  headers: {
      
  }
});