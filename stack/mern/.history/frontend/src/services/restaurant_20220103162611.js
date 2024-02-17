import http from '../http-common'

class RestaurantDataService {
  getAll(page = 0) {
    return http.get(`?page=${page}`);
  }

  createReview(data) {
    return http.post("/review", data);
  }
    Review(data) {
    return http.post("/review", data);
  }
}
export default new RestaurantDataService();