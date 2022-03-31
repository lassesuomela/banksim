
<template>
    <div class="dashboard">
        <app-sidebar/>
        
        <v-row>
            <v-col lg="7" cols="12">
                <v-row>
                    <v-col lg="6" cols="12" v-for="(item,index) in activityLog" :key="index">
                        <v-card elevation="2" class="rounded-lg">
                            <v-card-text class="d-flex justify-space-between align-center">
                                <div>
                                    <strong>{{ item.title }}</strong> <br>
                                </div>
                                <v-avatar size="60" :color="item.color" style="border: 3px solid #444">
                                    <span style="color: white">{{item.amount}} €</span>
                                </v-avatar>
                            </v-card-text>
                            <v-card-actions class="d-flex justify-space-between">
                            </v-card-actions>
                        </v-card>
                    </v-col>
                </v-row>
            </v-col>
        </v-row>
    </div>
</template>

<script>
    import axios from "../axios";
    export default {
        name: "Dashboard",
        data() {
            return {
                activityLog: [
                    {title: 'All', amount: 50000, icon: 'mdi-account', color: 'cyan lighten-3'},
                    {title: 'saving balance', amount: 20000, icon: 'mdi-account-group-outline', color: 'green darken-2'},
                    {title: 'use balance', amount: 30000, icon: 'mdi-account-group-outline', color: 'blue-grey darken-1'},

                ],
            }
        },
        methods:{
            async getUserData(){
                const response = await axios.get("/api/user/info");
                this.fname = response.data.fname;
            }
        },
        mounted(){
            this.getUserData();
        }
    }
    
</script>

<style scoped>
    .overlap-icon {
        position: absolute;
        top: -33px;
        text-align: center;
        padding-top: 12px;
    }
</style>
