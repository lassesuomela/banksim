import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import AboutView from "../views/AboutView.vue"

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView,
    meta:{
      title: "Home"
    }
  },
  {
    path: '/about',
    name: 'about',
    component: AboutView,
    meta:{
      title: "About"
    }
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

router.beforeEach((to,from,next)=>{
  document.title = `${to.meta.title}`;
  next();
});

export default router
