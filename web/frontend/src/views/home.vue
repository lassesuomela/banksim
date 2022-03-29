
<template>
    <div class="dashboard">
        <v-row>
            <v-col lg="7" cols="12">
                <v-alert dense text type="success">
                    Login Successfully! Welcome to <strong>Customer name</strong>
                </v-alert>
                <v-row>
                    <v-col lg="6" cols="12" v-for="(item,index) in activityLog" :key="index">
                        <v-card elevation="2" class="rounded-lg">
                            <v-card-text class="d-flex justify-space-between align-center">
                                <div>
                                    <strong>{{ item.title }}</strong> <br>
                                    <span>Last 3 weeks</span>
                                </div>
                                <v-avatar size="60" :color="item.color" style="border: 3px solid #444">
                                    <span style="color: white">{{item.amount}} +</span>
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
    export default {
        name: "Dashboard",
        data() {
            return {
                activityLog: [
                    {title: 'Total Products', amount: 50, icon: 'mdi-account', color: 'cyan lighten-3'},
                    {title: 'Total Customer', amount: 3433, icon: 'mdi-account-group-outline', color: 'green darken-2'},
                    {title: 'Total Sale', amount: 3433, icon: 'mdi-account-group-outline', color: 'blue-grey darken-1'},

                ],
            }
        },
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
