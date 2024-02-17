import http from '../http-common'

class RestaurantDataService {
  getAll(page = 0) {
    return http.get(`?page=${page}`);
  }

  createReview(data) {
    return http.post("/review", data);
  }
  updateReview(data) {
    return http.put("/review", data);
  }
}
export default new RestaurantDataService();