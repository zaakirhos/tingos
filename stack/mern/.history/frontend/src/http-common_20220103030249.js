import axios from 'axios'

export default axios.create({
  baseURL: "http://localhost:8000/api/v1/restaurants",
  headers: {
      "Content-Type": "application/json"
  }
});